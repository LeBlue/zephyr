/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 * Copyright (c) 2020 Prevas A/S
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <bluetooth/bluetooth.h>
#include <bluetooth/conn.h>
#include <bluetooth/gatt.h>
#include <mgmt/smp_bt.h>

#define LOG_LEVEL LOG_LEVEL_DBG
#include <logging/log.h>
LOG_MODULE_REGISTER(smp_bt_sample);

static struct k_work advertise_work;

static const struct bt_data ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA_BYTES(BT_DATA_UUID128_ALL,
		      0x84, 0xaa, 0x60, 0x74, 0x52, 0x8a, 0x8b, 0x86,
		      0xd3, 0x4c, 0xb7, 0x1d, 0x1d, 0xdc, 0x53, 0x8d),
};

static void advertise(struct k_work *work)
{
	int rc;

	bt_le_adv_stop();

	rc = bt_le_adv_start(BT_LE_ADV_CONN_NAME, ad, ARRAY_SIZE(ad), NULL, 0);
	if (rc) {
		LOG_ERR("Advertising failed to start (rc %d)", rc);
		return;
	}

	LOG_INF("Advertising successfully started");
}

static void connected(struct bt_conn *conn, uint8_t err)
{
	if (err) {
		LOG_ERR("Connection failed (err 0x%02x)", err);
	} else {
		LOG_INF("Connected");
	}
}

static void disconnected(struct bt_conn *conn, uint8_t reason)
{
	LOG_INF("Disconnected (reason 0x%02x)", reason);
	k_work_submit(&advertise_work);
}


#if IS_ENABLED(CONFIG_BT_SMP)

#define FIXED_PASSKEY 0

static void identity_resolved(struct bt_conn *conn, const bt_addr_le_t *rpa,
			      const bt_addr_le_t *identity)
{
	char addr_identity[BT_ADDR_LE_STR_LEN];
	char addr_rpa[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(identity, addr_identity, sizeof(addr_identity));
	bt_addr_le_to_str(rpa, addr_rpa, sizeof(addr_rpa));

	LOG_INF("Identity resolved %s -> %s", addr_rpa, addr_identity);
}

static void security_changed(struct bt_conn *conn, bt_security_t level,
			     enum bt_security_err err)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	if (!err) {
		LOG_INF("Security changed: %s level %u", addr, level);
	} else {
		LOG_INF("Security failed: %s level %u err %d", addr, level, err);
	}
}

static void auth_cancel(struct bt_conn *conn)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	LOG_WRN("Pairing cancelled: %s", addr);
}

static void pairing_complete(struct bt_conn *conn, bool bonded)
{
	LOG_INF("Pairing Complete");
}

static void pairing_failed(struct bt_conn *conn, enum bt_security_err reason)
{
	LOG_ERR("Pairing Failed (%d). Disconnecting.", reason);
	bt_conn_disconnect(conn, BT_HCI_ERR_AUTH_FAIL);
}

#if IS_ENABLED(CONFIG_BT_FIXED_PASSKEY)

// static struct k_work confirm_work;
// static struct bt_conn *connection_confirm;

// static void confirm(struct k_work *work)
// {
// 	bt_conn_auth_pairing_confirm(connection_confirm);
// 	bt_conn_unref(connection_confirm);
// }

static void pairing_confirm(struct bt_conn *conn)
{
	LOG_INF("Confirming pairing");
	/* canceling works */
	//bt_conn_auth_cancel(conn);

	/* sync call does nothing (pairing canceled after timeout) */
	//bt_conn_auth_pairing_confirm(conn);

	/* delayed does nothing (pairing canceled after timeout) */
	// connection_confirm = bt_conn_ref(conn);

	// k_work_init(&confirm_work, confirm);
	// k_work_submit(&confirm_work);
}

#else /* !IS_ENABLED(CONFIG_BT_FIXED_PASSKEY) */
static void auth_passkey_display(struct bt_conn *conn, unsigned int passkey)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	LOG_INF("Passkey for %s: %06u", addr, passkey);
}
#endif /* !IS_ENABLED(CONFIG_BT_FIXED_PASSKEY) */

static struct bt_conn_auth_cb auth_cb_display = {
	.passkey_entry = NULL,
	.cancel = auth_cancel,
	.pairing_complete = pairing_complete,
	.pairing_failed = pairing_failed,
#if IS_ENABLED(CONFIG_BT_FIXED_PASSKEY)
	.pairing_confirm = NULL /* pairing_confirm *//* if callback is set, authentication times out */,
	.passkey_display = NULL,
#else
	.pairing_confirm = NULL,
	.passkey_display = auth_passkey_display,
#endif /* IS_ENABLED(CONFIG_BT_FIXED_PASSKEY) */
};

#endif /* IS_ENABLED(CONFIG_BT_SMP) */

static struct bt_conn_cb conn_callbacks = {
	.connected = connected,
	.disconnected = disconnected,
#if IS_ENABLED(CONFIG_BT_SMP)
	.identity_resolved = identity_resolved,
	.security_changed = security_changed,
#endif /* IS_ENABLED(CONFIG_BT_SMP) */
};

static void bt_ready(int err)
{
	if (err) {
		LOG_ERR("Bluetooth init failed (err %d)", err);
		return;
	}

	if (IS_ENABLED(CONFIG_BT_SMP) && IS_ENABLED(CONFIG_BT_FIXED_PASSKEY)) {
		err = bt_passkey_set(FIXED_PASSKEY);
		if (err) {
			LOG_ERR("Setting fixed passkey failed (err %d)", err);
			return;
		}
	}

	LOG_INF("Bluetooth initialized");

	k_work_submit(&advertise_work);
}

void start_smp_bluetooth(void)
{
	k_work_init(&advertise_work, advertise);

	/* Enable Bluetooth. */
	int rc = bt_enable(bt_ready);

	if (rc != 0) {
		LOG_ERR("Bluetooth init failed (err %d)", rc);
		return;
	}

	if (IS_ENABLED(CONFIG_BT_SMP)) {
		bt_conn_auth_cb_register(&auth_cb_display);
	}

	bt_conn_cb_register(&conn_callbacks);

	/* Initialize the Bluetooth mcumgr transport. */
	smp_bt_register();
}

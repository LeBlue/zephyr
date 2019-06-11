/*
 * Copyright (c) 2019 Matthias Wauer
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <sensor.h>

void main(void)
{
	struct device *dev = device_get_binding("BMA280");

	if (dev == NULL) {
		printk("Could not get BMA280 device\n");
		return;
	}

	printk("dev %p name %s\n", dev, dev->config->name);

	while (1) {
		struct sensor_value accel_xyz[3];

		sensor_sample_fetch(dev);
		sensor_channel_get(dev, SENSOR_CHAN_ACCEL_XYZ, accel_xyz);
		/*sensor_channel_get(dev, SENSOR_CHAN_ACCEL_Y, &accel_y);
		sensor_channel_get(dev, SENSOR_CHAN_ACCEL_Z, &accel_z); */

		printk("x: %d.%06d; y: %d.%06d; z: %d.%06d\n",
		      accel_xyz[0].val1, accel_xyz[0].val2, accel_xyz[1].val1, accel_xyz[1].val2,
		      accel_xyz[2].val1, accel_xyz[2].val2);

		k_sleep(1000);
	}
}

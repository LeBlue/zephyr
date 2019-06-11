.. _bma280:

BMA280 Accelerometer Sensor
###########################

Overview
********

This sample application periodically reads accelerometer data from
the BMA280 device that implements SENSOR_CHAN_ACCEL_X, SENSOR_CHAN_ACCEL_Y,
and SENSOR_CHAN_ACCEL_Z. This sample checks the sensor in polling mode (without
interrupt trigger).

Building and Running
********************

This sample application uses an BMA280 sensor connected to an Calliope mini board via I2C.
See `bma280 datasheet`_.

.. zephyr-app-commands::
   :zephyr-app: samples/sensors/bma280
   :board: calliope_mini
   :goals: build
   :compact:


Sample Output
=============
To check output of this sample , any serial console program can be used.
This example uses ``picocom`` on the serial port ``/dev/ttyUSB0``:

.. code-block:: console

        $ sudo picocom -D /dev/ttyUSB0

.. code-block:: console

        x: 27.950000; y: 100.571027; z: 61.014648
        x: 27.940000; y: 100.570269; z: 61.012695
        x: 27.950000; y: 100.570695; z: 61.002929

.. _bma280 datasheet: https://ae-bst.resource.bosch.com/media/_tech/media/datasheets/BST-BMA280-DS000.pdf
.. _calliope:

Calliope mini
##############

Overview
********

The Calliope mini is an 
ARM-based embedded system Calliope mini is a small educational development board 
made for primary school and up in Germany based on the bbc:microbit.

The board is 4 cm × 5 cm and has an ARM Cortex-M0 processor, accelerometer and
magnetometer sensors, Bluetooth and USB connectivity, a display consisting of
25 LEDs, two programmable buttons, and can be powered by either USB or an
external battery pack. The device inputs and outputs are through five ring
connectors that are part of the 23-pin edge connector.

* :abbr:`NVIC (Nested Vectored Interrupt Controller)`
* :abbr:`RTC (nRF RTC System Clock)`
* UART
* GPIO
* FLASH
* RADIO (Bluetooth Low Energy)

.. figure:: img/Calliope_mini_1.3_pinout.png
     :width: 442px
     :align: center
     :alt: Calliope mini

     Calliope mini (Credit: https://calliope-mini.github.io/v10/)

More information about the board can be found at the `calliope website`_.

Hardware
********

The Calliope mini has the following physical features:

* 25 individually-programmable LEDs, compatible with :ref:`bbc microbit` display
* 1 RGB LED
* 2 programmable buttons
* Physical connection pins
* Light and temperature sensors ? TODO
* Motion sensors (accelerometer, gyroscope and compass)
* Wireless Communication, via Radio and Bluetooth
* USB interface


Supported Features
==================

The calliope board configuration supports the following nRF51
hardware features:

+-----------+------------+----------------------+
| Interface | Controller | Driver/Component     |
+===========+============+======================+
| NVIC      | on-chip    | nested vectored      |
|           |            | interrupt controller |
+-----------+------------+----------------------+
| RTC       | on-chip    | system clock         |
+-----------+------------+----------------------+
| UART      | on-chip    | serial port          |
+-----------+------------+----------------------+
| GPIO      | on-chip    | gpio                 |
+-----------+------------+----------------------+
| FLASH     | on-chip    | flash                |
+-----------+------------+----------------------+
| RADIO     | on-chip    | Bluetooth            |
+-----------+------------+----------------------+

Programming and Debugging
*************************

Flashing
========

Build and flash applications as usual (see :ref:`build_an_application` and
:ref:`application_run` for more details).

Here is an example for the :ref:`hello_world` application.

First, run your favorite terminal program to listen for output.

.. code-block:: console

   $ minicom -D <tty_device> -b 115200

Replace :code:`<tty_device>` with the port where the board nRF51 DK
can be found. For example, under Linux, :code:`/dev/ttyACM0`.

Then build and flash the application in the usual way.

.. zephyr-app-commands::
   :zephyr-app: samples/hello_world
   :board: calliope
   :goals: build flash


References
**********

.. target-notes::

.. _calliope website: https://calliope.cc/
.. _calliope githubio: https://calliope-mini.github.io/v10/
.. _calliope github: https://github.com/calliope-mini


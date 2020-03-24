#!/bin/sh

./make-renatocaval-nyq.sh

echo "Set keyboard on RESET mode now."

echo "You have 3 seconds"
sleep 1s

echo "2 seconds"
sleep 1s

echo "1 second"
sleep 1s

dfu-util -a 0 -d 0482:df11 -s 0x8000000:leave -D keebio_nyquist_rev2_renatocaval.hex

#!/bin/bash -e
# Note the -e flag: This stops the execution of this script when an error occurs.
test "$(./maidenhead.o 0 0)" == 'JJ00aa00AA99' && (echo 'PASS: Source Coodinate'; exit 0) || (exit 1)
test "$(./maidenhead.o 48.858093 2.294694)" == 'JN18du55IW76' && (echo 'PASS: EU, France, Paris, Eiffel Tower'; exit 0) || (exit 1)
test "$(./maidenhead.o 52.374355 4.897960)" == 'JO22ki79SU12' && (echo 'PASS: EU, The Netherlands, Amsterdam, Oude Kerk'; exit 0) || (exit 1)
test "$(./maidenhead.o 26.011280 -80.142967)" == 'EL96wa22UQ29' && (echo 'PASS: USA, FL, Hollywood'; exit 0) || (exit 1)
test "$(./maidenhead.o 51.508530 -0.076132)" == 'IO91xm02UB71' && (echo 'PASS: EU, Great Britain, London, The Tower of London'; exit 0) || (exit 1)
test "$(./maidenhead.o 360 360)" == 'JJ00aa00AA99' && (echo 'PASS: Reset Coordinate'; exit 0) || (exit 1)
echo 'All tests passed';
exit 0

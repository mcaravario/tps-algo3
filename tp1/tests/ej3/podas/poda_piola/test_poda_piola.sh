# !/bin/bash
CANT_PRODUCTOS=$1
UMBRAL=$2
END=$3
INC=$4
ITERACIONES=$5

while ((CANT_PRODUCTOS<END)); do
        ./prom $CANT_PRODUCTOS $UMBRAL | ./ej3-test-cp $ITERACIONES
        let CANT_PRODUCTOS=$CANT_PRODUCTOS+$INC
done

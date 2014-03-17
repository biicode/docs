#!/bin/sh
while [ true ]
do
    sphinx-build -b html . _build/html
    sleep 5
done

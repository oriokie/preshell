#!/bin/bash
if [ -e /proc/sys/kernel/pid_max ]; then
	cat /proc/sys/kernel/pid_max
else
	echo "Error. Path not found"
	exit 1
fi

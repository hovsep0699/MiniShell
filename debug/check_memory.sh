#! /bin/bash

`ps > tmp_ps`;
arg=`grep ../bin/minishell tmp_ps | awk '{if ($1 !="") print $1}'`;
if [ ! $arg == "" ]; then
    leaks $arg;
fi
`rm -f tmp_ps`
#!/usr/bin/bash

#全局变量和局部变量

sample_text="global variable"

foo(){
	local sample_text="local variable"
	echo "function foo is executing $sample_text"
	echo $sample_text
}

echo 'script starting'
echo $sample_text

foo

echo "script ended"
echo $sample_text

exit 0

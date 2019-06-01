<?php 

$ret = meminfo_dump();

file_put_contents(__DIR__."/test1.json", $ret);
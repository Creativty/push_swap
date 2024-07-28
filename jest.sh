#!/usr/bin/env bash
set +xe

test_cases=',1 3 5 4 6 "3 2" 7,8 1h 3,96 966 9666 99999999999999999999999999999999'

IFS=','; for test_case in ${test_cases[@]}
do
	actual="$(timeout 1 ./push_swap $test_case 2>&1)"
	expected="$(timeout 1 ./checker_OS $test_case 2>&1)"
	if [[ $actual != $expected ]]
	then
		echo failure: $test_case has different responses: \' $actual \' vs \' $expected \'
	else
		echo success: $test_case
	fi
done

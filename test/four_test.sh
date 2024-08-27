#!/bin/bash

# 正しい出力
correct_output="1 2 3 4"

# テストケースの配列
test_cases=(
    "1 2 3 4"
    "1 2 4 3"
    "1 3 2 4"
    "1 3 4 2"
    "1 4 2 3"
    "1 4 3 2"
    "2 1 3 4"
    "2 1 4 3"
    "2 3 1 4"
    "2 3 4 1"
    "2 4 1 3"
    "2 4 3 1"
    "3 1 2 4"
    "3 1 4 2"
    "3 2 1 4"
    "3 2 4 1"
    "3 4 1 2"
    "3 4 2 1"
    "4 1 2 3"
    "4 1 3 2"
    "4 2 1 3"
    "4 2 3 1"
    "4 3 1 2"
    "4 3 2 1"
)

# 各テストケースを実行
for test_case in "${test_cases[@]}"; do
    echo "Testing: ./push_swap $test_case"
    output=$(./push_swap $test_case | tail -n 1 | xargs)  # `xargs` を使用して余分なスペースを削除
    if [ "$output" = "$correct_output" ]; then
        echo -e "\e[32mOK\e[0m"
    else
        echo -e "\e[31mKO: Expected '1 2 3 4', but got '$output'\e[0m"
    fi
    echo ""
done

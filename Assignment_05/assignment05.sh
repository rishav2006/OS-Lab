#!/bin/bash
# ============================================================
# OS Lab - Assignment 05: Arrays in Shell
# ============================================================

echo "======================================"
echo "  OS Lab Assignment 05 - Arrays"
echo "======================================"

# -------------------------------------------------------
# Q1: Display the diamond/hourglass pattern
# -------------------------------------------------------
echo ""
echo "--- Q1: Pattern Display ---"
echo "Pattern:"
echo "1"
echo "1 1"
echo "1 1 1"
echo "1 1 1 1"
echo "1 1 1"
echo "1 1"
echo "1"

# -------------------------------------------------------
# Q2: Menu-driven: Sum and Bubble Sort of 10 numbers
# -------------------------------------------------------
q2_menu() {
    arr=()
    echo ""
    echo "--- Q2: Input 10 Numbers ---"
    for ((i = 0; i < 10; i++)); do
        read -p "  Enter number $((i + 1)): " val
        arr+=("$val")
    done

    while true; do
        echo ""
        echo "Menu:"
        echo "1. Sum of array elements"
        echo "2. Bubble sort"
        echo "3. EXIT"
        read -p "Choice: " ch
        case $ch in
            1)
                sum=0
                for v in "${arr[@]}"; do sum=$((sum + v)); done
                echo "Sum = $sum"
                ;;
            2)
                sorted=("${arr[@]}")
                n=${#sorted[@]}
                for ((i = 0; i < n - 1; i++)); do
                    for ((j = 0; j < n - i - 1; j++)); do
                        if [ "${sorted[$j]}" -gt "${sorted[$((j + 1))]}" ]; then
                            tmp="${sorted[$j]}"
                            sorted[$j]="${sorted[$((j + 1))]}"
                            sorted[$((j + 1))]="$tmp"
                        fi
                    done
                done
                echo "Sorted array: ${sorted[*]}"
                ;;
            3) break ;;
            *) echo "Invalid choice." ;;
        esac
    done
}

# -------------------------------------------------------
# Q3: Menu-driven: 10 consecutive primes, max and min
# -------------------------------------------------------
q3_menu() {
    echo ""
    echo "--- Q3: 10 Consecutive Prime Numbers ---"
    primes=()
    n=2
    while [ ${#primes[@]} -lt 10 ]; do
        is_prime=1
        for ((i = 2; i * i <= n; i++)); do
            if [ $((n % i)) -eq 0 ]; then is_prime=0; break; fi
        done
        [ $is_prime -eq 1 ] && primes+=($n)
        ((n++))
    done
    echo "First 10 primes: ${primes[*]}"

    while true; do
        echo ""
        echo "Menu:"
        echo "1. Sum of these primes"
        echo "2. Max and Min"
        echo "3. EXIT"
        read -p "Choice: " ch
        case $ch in
            1)
                sum=0
                for v in "${primes[@]}"; do sum=$((sum + v)); done
                echo "Sum = $sum"
                ;;
            2)
                max=${primes[0]}; min=${primes[0]}
                for v in "${primes[@]}"; do
                    [ "$v" -gt "$max" ] && max=$v
                    [ "$v" -lt "$min" ] && min=$v
                done
                echo "Max = $max, Min = $min"
                ;;
            3) break ;;
            *) echo "Invalid choice." ;;
        esac
    done
}

# -------------------------------------------------------
# Q4: Menu-driven: Merge two arrays, find & delete duplicates
# -------------------------------------------------------
q4_menu() {
    echo ""
    echo "--- Q4: Two Arrays - Merge, Duplicates ---"
    arr1=(10 20 30 40 50)
    arr2=(30 40 60 70 80)
    echo "Array 1: ${arr1[*]}"
    echo "Array 2: ${arr2[*]}"

    while true; do
        echo ""
        echo "Menu:"
        echo "1. Merge arrays (without 3rd array)"
        echo "2. Display duplicate element locations"
        echo "3. Delete duplicates"
        echo "4. EXIT"
        read -p "Choice: " ch
        case $ch in
            1)
                for v in "${arr2[@]}"; do arr1+=("$v"); done
                echo "Merged array (arr1 now): ${arr1[*]}"
                ;;
            2)
                echo "Duplicate locations in merged array:"
                n=${#arr1[@]}
                for ((i = 0; i < n; i++)); do
                    for ((j = i + 1; j < n; j++)); do
                        if [ "${arr1[$i]}" -eq "${arr1[$j]}" ]; then
                            echo "  Value ${arr1[$i]} at index $i and $j"
                        fi
                    done
                done
                ;;
            3)
                unique=()
                for v in "${arr1[@]}"; do
                    dup=0
                    for u in "${unique[@]}"; do
                        [ "$v" -eq "$u" ] && dup=1 && break
                    done
                    [ $dup -eq 0 ] && unique+=("$v")
                done
                arr1=("${unique[@]}")
                echo "Array after removing duplicates: ${arr1[*]}"
                ;;
            4) break ;;
            *) echo "Invalid choice." ;;
        esac
    done
}

# -------------------------------------------------------
# Q5: Menu-driven: Reverse array, find element at location
# -------------------------------------------------------
q5_menu() {
    echo ""
    echo "--- Q5: Reverse and Find by Index ---"
    arr=(15 42 7 99 23 56 8 31 77 4)
    echo "Array: ${arr[*]}"

    while true; do
        echo ""
        echo "Menu:"
        echo "1. Print array in reverse"
        echo "2. Find element by index"
        echo "3. EXIT"
        read -p "Choice: " ch
        case $ch in
            1)
                echo "Reversed:"
                n=${#arr[@]}
                for ((i = n - 1; i >= 0; i--)); do printf "${arr[$i]} "; done
                echo ""
                ;;
            2)
                read -p "Enter index (0-$((${#arr[@]} - 1))): " idx
                if [ "$idx" -ge 0 ] && [ "$idx" -lt "${#arr[@]}" ]; then
                    echo "Element at index $idx = ${arr[$idx]}"
                else
                    echo "Index out of bounds."
                fi
                ;;
            3) break ;;
            *) echo "Invalid choice." ;;
        esac
    done
}

# -------------------------------------------------------
# Q6: Concatenate two files line by line into third file
# -------------------------------------------------------
q6_concat() {
    echo ""
    echo "--- Q6: Concatenate Two Files Line by Line ---"
    read -p "Enter first file name : " f1
    read -p "Enter second file name: " f2
    read -p "Enter result file name : " f3

    if [ ! -f "$f1" ] || [ ! -f "$f2" ]; then
        echo "One or both input files not found."
        return
    fi

    paste "$f1" "$f2" > "$f3"
    echo "Result stored in '$f3':"
    cat "$f3"
}

# -------------------------------------------------------
# Q7: Store files into directories of max size X
# -------------------------------------------------------
q7_split_dirs() {
    echo ""
    echo "--- Q7: Split Files into Directories of Max Size X ---"
    read -p "Enter source directory: " srcdir
    read -p "Enter max files per dir (X): " X

    if [ ! -d "$srcdir" ]; then
        echo "Directory '$srcdir' not found."
        return
    fi

    count=0
    dirnum=1
    mkdir -p "${srcdir}_${dirnum}"
    for f in "$srcdir"/*; do
        [ -f "$f" ] || continue
        if [ $count -ge "$X" ]; then
            ((dirnum++))
            mkdir -p "${srcdir}_${dirnum}"
            count=0
        fi
        cp "$f" "${srcdir}_${dirnum}/"
        ((count++))
        echo "  Copied $(basename "$f") -> ${srcdir}_${dirnum}/"
    done
    echo "Done. Created $dirnum director(y/ies)."
}

# --- Run all sections ---
q2_menu
q3_menu
q4_menu
q5_menu
q6_concat
q7_split_dirs

echo ""
echo "======================================"
echo "  Assignment 05 Complete"
echo "======================================"

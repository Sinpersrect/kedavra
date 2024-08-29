oracle=./Benchmark/$1/parse_$1
if [ "$1" = "minic" ]; then
    oracle=./Benchmark/$1/parse_$1.py
fi
python3 infer.py $oracle ./Benchmark/$1/$1-train-$2 ./Benchmark/$1/$1-test $1-$2
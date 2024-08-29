for bench in arith fol json lisp mathexpr turtle "while" xml tinyc curl minic; do
    for seed in r0; do
	    bash runscript.sh $bench $seed
    done
done

for bench in json lisp turtle "while" xml tinyc curl; do
    for seed in r1 r2; do
	    bash runscript.sh $bench $seed
    done
done

for bench in tinyc; do
    for seed in r5; do
	    bash runscript.sh $bench $seed
    done
done
## Introduction

Kedavra is a tool used to infer grammar from a set of example strings and a black box parser.

## Installation
Recommended to use Docker image environments provided by Arvada or Treevada for running.

```
pip install tqdm
pip install colored
pip install lark
```
## Running Kedavra

Suppose you have a directory containing a set of examples, `TRAIN_DIR`, a directory containing a set of test examples, `TEST_DIR` , and an oracle for a valid example, `ORACLE_CMD`. The restrictions on `ORACLE_CMD` are as follows:

- `ORACLE_CMD filename` should run the oracle on the file with name `filename`
- `ORACLE_CMD filename` should return 0 if the example in `filename` is valid, and an exit code greater than 0 if it is invalid.

You can then run Kedavra via:
```
$ python3 infer.py ORACLE_CMD TRAIN_DIR TEST_DIR LOG_FILE
```
this will create three files:

`LOG_FILE`: record the inferred grammar and infer time.

`LOG_FILE.eval`: record the evaluation of the grammar.

`LOG_FILE.gramdict`: record the grammar dict.

## Quick Start

```
bash runscript GRAMMAR SEED
```
The possible values of `GRAMMAR`:

- arith
- fol
- mathexpr
- json
- lisp
- turtle
- xml
- while
- curl
- tinyc
- minic

The posssible values for `SEED`:
- r0
- r1
- r2
- r5

Here `arith`, `fol`, `minic` and `mathexpr` only have `r0`, and only `tinyc` has `r5`

Example:
```
bash runscript tinyc r5
```
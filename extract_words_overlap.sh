#!/bin/sh
for i in 1 2 3 4 5
do
  rm names-warmup1.txt
  rm names-warmup2.txt
  rm names-warmup3.txt
  rm names-warmup4.txt
  rm names1.txt
  rm names2.txt
  rm routing.txt
  ./extract_words ../word2vec/trunk/vectors.bin names-warmup1 $1 any
  ./extract_words ../word2vec/trunk/vectors.bin names-warmup2 $1 any
  ./extract_words ../word2vec/trunk/vectors.bin names-warmup3 $1 any
  ./extract_words ../word2vec/trunk/vectors.bin names-warmup4 $1 any
  ./extract_words ../word2vec/trunk/vectors.bin names1 $2 lower
  ./extract_words_overlap ../word2vec/trunk/vectors.bin names2 $2 upper names1 $4
  ./extract_words ../word2vec/trunk/vectors.bin routing $3 any
  #./waf --run "ndn-fuzzy-test-abilene --fibSize=$3 --simTime=70"
  ./waf --run "ndn-fuzzy-test-wait --fibSize=$3 --simTime=70 --waitTime=$5"
done

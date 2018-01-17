import sys
from nltk.corpus import wordnet as wn
from nltk.corpus.reader.wordnet import WordNetError

similarity = 0
line_counter = 0

with open(sys.argv[1]) as f:
    for line in f:
        try:
            word1 = wn.synset(line.split()[0] + '.n.01')
        except WordNetError:
            # words = wn.synsets(line.split()[0])
            # if (len(words) > 0):
            #     word1 = words[0]
            # else:
            #     continue
            continue
        try:
            word2 = wn.synset(line.split()[1] + '.n.01')
        except WordNetError:
            # words = wn.synsets(line.split()[0])
            # if (len(words) > 0):
            #     word2 = words[0]
            # else:
            #     continue
            continue
        print word1
        print word2
        line_counter += 1
        similarity += word1.wup_similarity(word2)
        print("Similarity: {0}".format(similarity))

print ("Average similarity: {0}".format(similarity / line_counter))

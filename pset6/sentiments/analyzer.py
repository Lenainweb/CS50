from  nltk.tokenize  import  TweetTokenizer

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        self.positive = set()
        self.negative = set()

        file = open(positives, "r")
        for line in file:
            if ';' in line:
                continue
            self.positive.add(line.rstrip("\n"))
        file.close()

        file = open(negatives, "r")
        for line in file:
            if ';' in line:
                continue
            self.negative.add(line.rstrip("\n"))
        file.close()

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""

        tknzr  =  TweetTokenizer()
        tokens = tknzr.tokenize(text)

        posit, negat = 0.0, 0.0
        if len(tokens) == 1:
            if text.lower() in self.positive:
                posit = 1.0
            elif text.lower() in self.negative:
                negat = 1.0
        else:
            for word in tokens:
                str(word)
                if word.lower() in self.positive:
                    posit += 1.0
                elif word.lower() in self.negative:
                    negat += 1.0

        return posit - negat

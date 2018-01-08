from flask import Flask, redirect, render_template, request, url_for

import os
import sys

import helpers
from analyzer import Analyzer

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():

    # validate screen_name
    screen_name = request.args.get("screen_name", "")
    if not screen_name:
        return redirect(url_for("index"))

    # get screen_name's tweets
    tweets = helpers.get_user_timeline(screen_name, 100)

    positives = os.path.join(sys.path[0], "positive-words.txt")
    negatives = os.path.join(sys.path[0], "negative-words.txt")

    if tweets == None:
        sys.exit("Usage: incorect @screen_name")

    posit, negat, neut = 0.0, 0.0, 0.0

    for tweet in tweets:

        # instantiate analyzer
        analyzer = Analyzer(positives, negatives)
        score = analyzer.analyze(tweet)

        if score > 0.0:
            posit += 1.0
        elif score < 0.0:
            negat += 1.0
        else:
            neut += 1.0

    one_percent  = (posit + negat + neut) / 100
    positive = one_percent * posit
    negative = one_percent * negat
    neutral = one_percent * neut

    # generate chart
    chart = helpers.chart(positive, negative, neutral)

    # render results
    return render_template("search.html", chart=chart, screen_name=screen_name)

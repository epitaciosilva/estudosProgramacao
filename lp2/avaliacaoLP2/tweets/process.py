from contextlib import redirect_stdout
import re

with open("tweets.in", encoding="utf-8") as f:
    tweets = [line.strip() for line in f.readlines()]
    tweets.sort()

with open("tweets.out", "w", encoding="utf-8") as f:
    with redirect_stdout(f):
        for tweet in tweets:
            fake_news = list(re.finditer("(RT @\w+)|(http[s]?\S+)", tweet))
            if len(fake_news) > 1 and "RT" in fake_news[0].group():
                print("{} {}".format(fake_news[0].group().split()[1], fake_news[1].group()))

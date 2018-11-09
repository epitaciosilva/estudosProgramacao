from contextlib import redirect_stdout
from re import findall

with open("tweets.in", encoding="utf-8") as f:
	tweets = [line.strip() for line in f.readlines()]
	tweets.sort()

with open("tweets.out", "w", encoding="utf-8") as f:
	with redirect_stdout(f):
		for tweet in tweets:
			for user,url in findall(r"RT (@\w+).*(http[s]?\S+).*", tweet):
				print("{} {}".format(user, url))
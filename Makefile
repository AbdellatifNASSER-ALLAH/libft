.PHONY: all

all: commit

commit: add
	git commit -m "msg"

add: status
	git add .

status: 
	git status

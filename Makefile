.PHONY: all commit add status

all: commit

commit: add
	@read -p "Enter commint: " MSG ;\
	git commit -m "$$MSG"

add: status
	@git add .
	@git status

status: 
	@git status

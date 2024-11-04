.PHONY: all commit add status pull rebase

all: push

push: commit
	@git push

commit: add
	@read -p "Enter commint: " MSG ;\
	git commit -m "$$MSG"

add: status
	@echo "adding..."
	@git add .
	@git status

status: 
	@git status

pull:
	@git pull

rebase: 
	@git pull --rebase

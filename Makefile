##
## EPITECH PROJECT, 2022
## B-PSU-400-PAR-4-1-nmobjdump-laetitia.bousch
## File description:
## Makefile
##

all:
	${MAKE} -C nm/
	${MAKE} -C objdump/

nm:
	${MAKE} -C nm/

objdump:
	${MAKE} -C objdump/

fclean:
	${MAKE} fclean -C nm/
	${MAKE} fclean -C objdump/

clean:
	${MAKE} clean -C nm/
	${MAKE} clean -C objdump/

re: fclean
	${MAKE} -C nm/
	${MAKE} -C objdump/

.PHONY: all nm objdump clean fclean re
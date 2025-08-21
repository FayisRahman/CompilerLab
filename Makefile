DIRS = spl xfs-interface xsm_dev

all:
	set -e; for d in $(DIRS); do $(MAKE) -C $$d ; done

clean:
	@cd xfs-interface && make clean
	@cd xsm_dev && make clean

SBT?=sbt
DRIVER?=DMAController.DMADriver
TB=ControllerSpec

SIZE=512
SIZE_HALF=256
IMG=ruru.png

TAG:=$(shell git describe --tags --abbrev=0)
export TAG

verilog:
	$(SBT) "runMain $(DRIVER) $(CONFIG_FILE)"

testsetup:
	convert -resize $(SIZE_HALF)x$(SIZE_HALF) $(IMG) img0.rgba
	convert -resize $(SIZE)x$(SIZE) $(IMG) img1.rgba
	convert -resize $(SIZE)x$(SIZE) $(IMG) img2.rgba

testM22Slave: testsetup 
	$(SBT) "Test / testOnly -t *$(TB)"
	convert -size $(SIZE)x$(SIZE) -depth 8 outDevice1AXI_AXIL_AXI.rgba outM22Slave1.png
	convert -size $(SIZE)x$(SIZE) -depth 8 outDevice2AXI_AXIL_AXI.rgba outM22Slave2.png

test: testM22Slave

testall: test
	$(SBT) "test"

clean:
	$(SBT) clean

.PHONY: verilog test testall

%:
	sphinx-build -M $@ docs build $(SPHINXOPTS) $(0)


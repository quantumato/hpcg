HPCG_DEPS = src/CG.cpp src/CG_ref.cpp src/TestCG.cpp src/ComputeResidual.cpp \
						src/ExchangeHalo.cpp src/ExchangeHaloRequest.cpp src/GenerateGeometry.cpp \
						src/GenerateProblem.cpp src/OptimizeProblem.cpp src/ReadHpcgDat.cpp src/ReportResults.cpp \
						src/SetupHalo.cpp src/TestSymmetry.cpp src/TestNorms.cpp src/WriteProblem.cpp \
						src/YAML_Doc.cpp src/YAML_Element.cpp src/ComputeDotProduct.cpp \
					src/ComputeDotProduct_ref.cpp src/finalize.cpp src/init.cpp src/mytimer.cpp src/ComputeSPMV.cpp \
					src/ComputeSPMV_ref.cpp src/ComputeSYMGS.cpp src/ComputeSYMGS_ref.cpp src/ComputeWAXPBY.cpp \
				src/ComputeWAXPBY_ref.cpp src/ComputeMG_ref.cpp src/ComputeMG.cpp src/ComputeProlongation_ref.cpp \
					src/ComputeRestriction_ref.cpp src/GenerateCoarseProblem.cpp \
					src/ComputeOptimalShapeXYZ.cpp src/MixedBaseCounter.cpp src/CheckAspectRatio.cpp

bin/test: src/main.cpp $(HPCG_DEPS)
	mpic++ -DHPCG_NOOPENMP -DHPCG_DEBUG -g -o bin/test src/main.cpp $(HPCG_DEPS)

const dictionary& pimpleDict = mesh.solutionDict().subDict("PIMPLE");

int nNonOrthCorr =
    pimpleDict.lookupOrDefault<int>("nNonOrthogonalCorrectors", 0);

if (pimple.finalIter())
{
    mesh.data::add("finalIteration", true);
}

if (frozenFlow)
{
    #include "EEqn.H"
}
else
{
    if (pimple.firstIter())
    {
        #include "rhoEqn.H"
    }

    #include "UEqn.H"
    #include "EEqn.H"

    // --- PISO loop
//    for (int corr=0; corr<nCorr; corr++)
    while (pimple.correct())
    {
        #include "pEqn.H"
    }

    turb.correct();

    rho = thermo.rho();
}

if (pimple.finalIter())
{
    mesh.data::remove("finalIteration");
}

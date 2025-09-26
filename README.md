# Biphasic Voronoi Cell-based Model (BVCBM)
![Simulation](https://img.shields.io/badge/Simulation-Agent--based%20models-blue)

This repo is a Python package wrapped the C++ implementation for following papers:
- [Calibration of agent based models for monophasic and biphasic tumour growth using approximate Bayesian computation](https://link.springer.com/article/10.1007/s00285-024-02045-4)

by Xiaoyu Wang, [Adrianne L. Jenner](https://www.adriannejenner.com/), [Robert Salomone](https://robsalomone.com/), [David J. Warne](https://sites.google.com/view/dj-warne) and [Christopher Drovandi](https://chrisdrovandi.weebly.com/)

Agent-based models are a class of models that can describe complicated phenomena by analysing the interactions between each agent. In cellular dynamics, treating each cell as an agent is a popular strategy. Prior research has sometimes ignored the geometries of agents and only considered their interactions. In the Voronoi cell-based model, the agent is modelled with Voronoi tesselation so that its shape is as accurate as reality.

***
## How to Install

You can use following line of code to install the BVCBM via `pip`:

```commandline
pip install git+https://github.com/john-wang1015/BVCBM.git
```

## How to Use

After successfully installed, you can use following code to import the model:

```python
import bvcbm
```

For use VCBM, you can use this `full_simulation`:

``` python
  volumes = bvcbm.full_simulation(
    p0=0.3,
    psc=0.1,
    dmax=150,
    gage=24,
    page=12,
    start_volume=1.0,
    simtime=30,
)

print(volumes)
```

and for BVCBM, you can use `full_simulation_biphasic`:
```python
volumes_biphasic = bvcbm.full_simulation_biphasic(
    p0_1=0.3, psc_1=0.1, dmax_1=150, gage_1=24, page=12,
    p0_2=0.2, psc_2=0.05, dmax_2=150, gage_2=24,
    tau=10.0,
    start_volume=1.0,
    simtime=30,
)

print(volumes)
```

All the parameters values can be user-defined and we recommend to use flat prior if you need to make inference.

## Reference
If you find the code useful for your research, please consider citing

```bib
  @article{wang2024calibration,
  title={Calibration of agent based models for monophasic and biphasic tumour growth using approximate Bayesian computation},
  author={Wang, Xiaoyu and Jenner, Adrianne L and Salomone, Robert and Warne, David J and Drovandi, Christopher},
  journal={Journal of Mathematical Biology},
  volume={88},
  number={3},
  pages={28},
  year={2024},
  publisher={Springer}
}
```
and
```bib
    @article{jenner2020enhancing,
  title={Enhancing oncolytic virotherapy: Observations from a Voronoi Cell-Based model},
  author={Jenner, Adrianne L and Frascoli, Federico and Coster, Adelle CF and Kim, Peter S},
  journal={Journal of Theoretical Biology},
  volume={485},
  pages={110052},
  year={2020},
  publisher={Elsevier}
}
```


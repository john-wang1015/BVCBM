"""Python interface for the BVCBM tumour growth model."""

from ._core import full_simulation, full_simulation_biphasic

__all__ = ["full_simulation", "full_simulation_biphasic"]
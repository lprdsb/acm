import wandb
import os

wandb.init(project="test")
wandb.save(os.path.abspath(__file__), policy="now")
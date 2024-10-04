import os

dir_path = "/home/porto/Documents/jumper/StickMan_graph/StickMan_run_right"

for file in os.listdir(dir_path):
   src = os.path.join(dir_path, file)
   # 48
   index_file = file[33] + file[34] + file[35]
   print(index_file)
   dest = os.path.join(dir_path, f'run_right{index_file}.png')
   os.rename(src, dest)
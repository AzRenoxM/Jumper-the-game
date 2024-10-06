import os

dir_path = "jumper/StickMan_graph/StickMan_run_right"

for file in os.listdir(dir_path):
   src = os.path.join(dir_path, file)
   
   index_file = file[9] + file[10] + file[11]
   print(index_file)

   dest = os.path.join(dir_path, f'run_right00{int(index_file) - 11}.png')
   os.rename(src, dest)
   # else:
   #    dest = os.path.join(dir_path, f'run_left0{index_file}.png')
import os
path = "/mnt/d/BrAIn/Images"

for i in range(1, 16):
  df = path + "/Type %d" % i
  folders = os.listdir(df)
  for folder in folders:
    dff = df + "/" + folder
    files = os.listdir(dff)
    for f in files:
      if (".csv" in f):
        ff = open(dff + "/" + f)
        lines = ff.readline()
        separators = lines.count(";")
        if (separators != 73):
          print("Deu merda T-T", separators)
        ff.close()
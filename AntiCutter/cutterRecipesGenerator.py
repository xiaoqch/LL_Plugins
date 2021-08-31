import glob
import json
import os

data=dict()
path=input("path of bedrock dedicated server:")
filelist=glob.glob(path+r"/behavior_packs/*/recipes/stonecutter_*")
for filepath in filelist:
    with open(filepath) as file:
        filedata=json.loads(file.read())
        # print(filepath)
        iptdata=filedata["minecraft:recipe_shapeless"]["ingredients"][0]
        iptname=iptdata["item"]
        iptaux=iptdata.get("data")
        if(not iptaux):
            iptaux=0
        ipt=iptname+":"+str(iptaux)
        optdata=filedata["minecraft:recipe_shapeless"]["result"]
        optname=optdata["item"]
        optaux=optdata.get("data")
        if(not optaux):
            optaux=0
        opt=optname+":"+str(optaux)
        optCount=optdata.get('count')
        if(not optCount):
            optCount=1
        if(ipt not in data.keys()):
            data[ipt]={}
        data[ipt][opt]=optCount
outputpath=os.path.join(path, "plugins/AntiCutter/cutter_recipes.json")
if(not os.path.exists(os.path.dirname(outputpath))):
    os.makedirs(os.path.dirname(outputpath))
# outputpath="cutter_recipes.json"
with open(outputpath,'w') as file:
    file.write(json.dumps(data,indent=4))

print("Generate finished.")
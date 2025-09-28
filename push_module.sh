#!/bin/bash

MY_REPO=git@github.com:LeMuffinMan/cpp_modules.git

if [ -z "$1" ] || [ -z "$2" ]; then 
  echo "Usage : ./push_module.sh <vog-repo> <module-to-push>"
  echo "Example : ./push_module.sh git@vogsphere.42lyon.fr:vogsphere/intra-uuid-<>-<login> 01"
  exit 1
fi

set -e

git clone $MY_REPO temp_source
cd temp_source

if [ ! -d "$2" ]; then
    echo "Erreur: Le module $2 n'existe pas dans le repo source"
    exit 1
fi

echo "Structure du module $2:"
ls -la "$2/"

cd ..

git clone $1 vogrepo
cd vogrepo

find . -maxdepth 1 ! -name '.git' ! -name '.' -exec rm -rf {} +

cp -r ../temp_source/$2/* .

cd ..
rm -rf temp_source

cd vogrepo
git add .
git commit -m "Add module $2 content" || true

git push origin master

echo "Push completed successfully!"
echo "Structure finale:"
ls -la

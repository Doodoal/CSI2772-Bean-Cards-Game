#!/bin/bash
if command -v g++ > /dev/null 2>&1; then

    rm -rf build && mkdir build

    
    outputFile="build/test.exe"
    sources=(   "src/test.cpp" 
                "src/Card.cpp"
                
            )


    sourcesString=$(printf " %s" "${sources[@]}")

    # Commande de compilation
    command="g++ -o $outputFile $sourcesString"

    echo "Compilation en cours ..."
    eval $command


    if [ -f "$outputFile" ]; then
        echo "Compilation reussie."
        echo "Fichier executable: $outputFile"

        # Run the executable
        echo "Execution du programme ..."
        echo "---------------------------------"
        echo ""
        
        
        ./$outputFile
    else
        echo "La compilation a echoue"
    fi

else
    echo "g++ n'est pas installe sur votre systeme. Veuillez l'installer pour compiler le programme."
    echo " Pour installer g++, veuillez executer la commande suivante :"
    echo "sudo apt-get install g++"

fi


#!/bin/bash

# Fonction pour exécuter une commande sur les deux shells et comparer les résultats
test_command() {
    command="$1"
    echo "Testing command: $command"

    # Exécute la commande sur votre shell personnalisé et capture la sortie et le code de sortie
    custom_output=$(./shell <<< "$command" 2>&1)
    custom_exit_code=$?

    # Exécute la commande sur sh et capture la sortie et le code de sortie
    sh_output=$(echo "$command" | sh 2>&1)
    sh_exit_code=$?

    # Compare les sorties
    if [ "$custom_output" = "$sh_output" ]; then
        echo "Output: MATCH"
    else
        echo "Output: MISMATCH"
        echo "Custom shell output:"
        echo "$custom_output"
        echo "Standard sh output:"
        echo "$sh_output"
    fi

    # Compare les codes de sortie
    if [ $custom_exit_code -eq $sh_exit_code ]; then
        echo "Exit code: MATCH ($custom_exit_code)"
    else
        echo "Exit code: MISMATCH (Custom: $custom_exit_code, sh: $sh_exit_code)"
    fi

    echo "----------------------------------------"
}

# Liste des commandes à tester
commands=(
    "ls"
    "lm"
    "ls -poyui"
    "/bin/ls"
    "/hgdsk"
    "echo Hello, World!"
    "pwd"
    "cat /etc/passwd"
    "nonexistent_command"
    "ls -l /tmp"
    " "
    "echo"
    "ls -la"
    "^c^c^dê^dê"
    "cat rfrrtr"
    "ls | grep shell"             # Commande avec un pipe
    "cat /etc/passwd | sort -r"   # Lecture et tri inverse
    "echo \$PATH"                 # Affichage d'une variable d'environnement
    "touch testfile; rm testfile" # Création et suppression immédiate
    "cd /tmp; pwd"                # Navigation et affichage du chemin
    "mkdir testdir; cd testdir; pwd; cd ..; rm -r testdir"  # Plusieurs commandes séquentielles
    "echo 'Hello' > output.txt; cat output.txt; rm output.txt"  # Redirection vers un fichier
    "ls /doesnotexist"            # Accès à un répertoire inexistant
    "echo 'Testing' | wc -c"      # Utilisation de pipe et comptage de caractères
    "cd"                          # Retour au répertoire home
    "exit"                        # Quitte le shell
    "sleep 2"                     # Commande avec délai
    "echo 'Infinite loop'; while :; do :; done"
)
# Exécute les tests pour chaque commande
for cmd in "${commands[@]}"; do
    test_command "$cmd"
done


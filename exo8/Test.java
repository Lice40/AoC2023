package exo8;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

class test {

    public static void main(String[] args) throws IOException {
        File f = new File(exo8.paths.puzzle);
        Scanner sc = new Scanner(f);
        Map<String, String[]> puzzleMap = new HashMap<String, String[]>();
        int step = 0;
        String instructions = sc.nextLine(), currentPos = "";
        String currentPaths[] = {};
        sc.nextLine();
        while (sc.hasNextLine()) {
            String line[] = sc.nextLine().split(" = ");
            String position = line[0];
            String paths[] = line[1].substring(1, line[1].length() - 1).split(", ");

            puzzleMap.put(position, paths);
        }
        currentPos = "AAA";
        currentPaths = puzzleMap.get(currentPos);
        while (!currentPos.equals("ZZZ")) {
            char currentInsruction = instructions.charAt(step % instructions.length());
            switch (currentInsruction) {
                case 'R':
                    currentPos = currentPaths[1];
                    currentPaths = puzzleMap.get(currentPos);
                    System.out.println("Départ à Droite, prochaine position: " + currentPos);
                    break;
                case 'L':
                    currentPos = currentPaths[0];
                    currentPaths = puzzleMap.get(currentPos);
                    System.out.println("Départ à Gauche, prochaine position: " + currentPos);
                    break;
                default:
                    System.out.println("instruction " + currentInsruction + " inconnue");
                    break;
            }
            step++;
            if (step > 18000) {
                break;
            }
        }
        sc.close();
        System.out.println("nombre d'étapes: " + step);

    }
}
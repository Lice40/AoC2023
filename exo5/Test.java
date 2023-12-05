package exo5;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

class test {
    public static void main(String[] args) throws IOException {
        File f = new File(exo5.paths.puzzle);
        Scanner sc = new Scanner(f);
        List<Integer> seeds = new ArrayList<Integer>();
        Map<Integer, Integer> seedMap = new HashMap<Integer, Integer>();
        int i = 1;
        while (sc.hasNextLine()) {
            String[] temp;
            String data = sc.nextLine();
            if (data.startsWith("seeds: ")) {
                // on parse les seeds;
                temp = data.split(": ")[1].split(" ");
                for (String elt : temp) {
                    seeds.add(Integer.parseInt(elt));
                    seedMap.put(Integer.parseInt(elt), 0);
                }

            }

            if (!data.isEmpty() && Character.isDigit(data.charAt(0))) {
                temp = data.split(" ");
                int seed = Integer.parseInt(temp[0]);
                int start = Integer.parseInt(temp[1]);
                int end = start + Integer.parseInt(temp[2]) - 1;

                for (Map.Entry<Integer, Integer> elt : seedMap.entrySet()) {
                    if (elt.getKey() >= start && elt.getKey() <= end) {
                        seedMap.put(elt.getKey(), seed);
                    }
                }
            }
        }
        for (Map.Entry<Integer, Integer> elt : seedMap.entrySet()) {
            System.out.println("Seed: " + elt.getKey() + ", Position: " + elt.getValue());
        }
        sc.close();
    }
}
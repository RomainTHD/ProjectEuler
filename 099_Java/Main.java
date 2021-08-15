import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

class Number {
    public final int base;
    public final int exp;
    public final int lineNo;

    public Number(int base, int exp, int lineNo) {
        this.base = base;
        this.exp = exp;
        this.lineNo = lineNo;
    }

    @Override
    public String toString() {
        return String.format("Number{base=%d, exp=%d, lineNo=%d}", this.base, this.exp, this.lineNo);
    }
}

public class Main {
    public static final String FILE_PATH = "./base_exp.txt";

    private static List<Number> loadData() throws IOException {
        List<Number> res = new ArrayList<>();

        BufferedReader reader = new BufferedReader(new FileReader(FILE_PATH));

        String line;
        String[] parts;
        int lineNo = 1;

        while ((line = reader.readLine()) != null) {
            parts = line.split(",");
            res.add(new Number(Integer.parseInt(parts[0]), Integer.parseInt(parts[1]), lineNo));
            ++lineNo;
        }

        return res;
    }

    private static Number processData(List<Number> data) {
        Number maxNumber = null;
        double maxNumberValue = 0.;

        for (Number number : data) {
            double value = Math.log(number.base) * number.exp;
            if (value > maxNumberValue || maxNumber == null) {
                maxNumber = number;
                maxNumberValue = value;
            }
        }

        return maxNumber;
    }

    public static void main(String[] args) throws IOException {
        List<Number> data = loadData();
        Number maxNumber = processData(data);
        System.out.println(maxNumber);
    }
}

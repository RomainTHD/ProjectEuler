fn days_in_month(month: u32, year: u32) -> u32 {
	if month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 {
		31
	} else if month == 2 {
		if year % 4 == 0 {
			if year % 100 == 0 {
				if year % 400 == 0 {
					29
				} else {
					28
				}
			} else {
				29
			}
		} else {
			28
		}
	} else {
		30
	}
}

fn main() {
	let mut sunday_count = 0;
	let mut day_count = 0;

	for month in 1..13 {
		day_count += days_in_month(month, 1900);
	}

	for year in 1901..2001 {
		for month in 1..13 {
			day_count += days_in_month(month, year);
			if day_count % 7 == 6 {
				sunday_count += 1;
			}
		}
	}

	println!("{}", sunday_count);
}

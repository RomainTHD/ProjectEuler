/// Tuple position to cache array index
fn pos_to_idx(src: (u32, u32), dst: (u32, u32)) -> usize {
	return (src.0 * (dst.1 + 1) + src.1) as usize;
}

/// Counts the number of paths from src to dst
fn count_paths(src: (u32, u32), dst: (u32, u32), cache: &mut [u64]) -> u64 {
	if cache[pos_to_idx(src, dst)] != 0 {
		// Cache hit
		return cache[pos_to_idx(src, dst)];
	}

	let mut result = 0;
	if src.0 < dst.0 {
		// Down
		result += count_paths((src.0 + 1, src.1), dst, cache);
	}
	if src.1 < dst.1 {
		// Right
		result += count_paths((src.0, src.1 + 1), dst, cache);
	}
	if src == dst {
		// Bottom right corner
		result += 1;
	}
	cache[pos_to_idx(src, dst)] = result;
	return result;
}

fn main() {
	let rows = 20;
	let cols = 20;
	let mut cache = vec![0; (rows + 1) * (cols + 1)];
	let count = count_paths((0, 0), (rows as u32, cols as u32), &mut cache);
	println!("{}", count);
}

let _ =
  let prob1 _ (x, y, vx, vy) = (vx, vy, y, -1.0 *. x) in
  Util.simulate_with_euler prob1 64

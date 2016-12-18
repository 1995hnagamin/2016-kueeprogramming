let mult_scalar_vector4 k (a, b, c, d) =
  (k *. a, k *. b, k *. c, k *. d)
let ( *: ) = mult_scalar_vector4

let plus_vector4 (a, b, c, d) (x, y, z, w) =
  (a +. x, b +. y, c +. z, d +. w)
let (+:) = plus_vector4

let minus_vector4 v w =
  v +: (-1.0 *: w)
let (-:) = minus_vector4

let abs_vector4 (a, b, c, d) =
  sqrt (List.fold_left (+.) 0.0 (List.map (fun x -> x *. x) [a; b; c; d]))

let mult_scalar_vector2 k (a, b) =
  (k *. a, k *. b)

let plus_vector2 (a, b) (x, y) = (a +. x, b +. y)

let minus_vector2 v w =
  plus_vector2 v (mult_scalar_vector2 (-1.0) w)

let abs_vector2 (a, b) =
  sqrt (a *. a +. b *. b)

let pi = 4.0 *. atan 1.0

let expand f init size =
  let rec loop lst i =
    match i with
    | 0 -> List.rev lst
    | _ -> loop ((f lst)::lst) (i - 1)
  in
  let len = List.length init in
  if size >= len then
    loop (List.rev init) (size - len)
  else
    raise (invalid_arg "Invalid size")

let expand1 f init size =
  let g = function
  | [] -> raise (invalid_arg "Empty list")
  | x::xs -> f x
  in
  expand g init size

let calcSSM phi h steps (t0, y0) =
  let develop (n, y) =
    let t = h *. (float_of_int n) in
    y +: (h *: (phi t y))
  in
  expand1 (fun (n, y) -> (n + 1, develop (n, y))) [(t0, y0)] steps

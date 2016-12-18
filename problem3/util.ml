let rec zipWith f xs ys =
  match (xs, ys) with
  | ([], []) -> []
  | (x::xs, y::ys) -> (f x y)::(zipWith f xs ys)
  | _ -> raise (invalid_arg "Different length")

let mult_scalar_vector k v = List.map (fun x -> k *. x) v
let ( *: ) = mult_scalar_vector

let plus_vector v w = zipWith (+.) v w
let (+:) = plus_vector

let minus_vector v w = v +: (-1.0 *: w)
let (-:) = minus_vector

let abs_vector v =
  sqrt (List.fold_left (+.) 0.0 (List.map (fun x -> x *. x) v))

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

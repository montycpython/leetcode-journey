defmodule Solution do
  @spec generate(num_rows :: integer) :: [[integer]]
  def generate(num_rows) when num_rows >= 1 do
    Enum.reduce(1..num_rows, [], fn row_num, acc ->
      prev_row = List.last(acc) || []
      row = build_row(row_num, prev_row)
      acc ++ [row]
    end)
  end

  defp build_row(1, _), do: [1]

  defp build_row(_n, prev_row) do
    [1] ++ inner_elements(prev_row) ++ [1]
  end

  defp inner_elements(row) do
    row
    |> Enum.chunk_every(2, 1, :discard)
    |> Enum.map(fn [a, b] -> a + b end)
  end
end

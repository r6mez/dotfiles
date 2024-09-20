require "nvchad.mappings"

-- add yours here

local map = vim.keymap.set

-- vim.api.nvim_set_keymap('n', '<leader>fm', ':%!clang-format<CR>', { noremap = true, silent = true })
map("n", ";", ":", { desc = "CMD enter command mode" })
map("i", "jk", "<ESC>")

-- map({ "n", "i", "v" }, "<C-s>", "<cmd> w <cr>")

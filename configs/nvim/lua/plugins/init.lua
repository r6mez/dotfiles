local plugins = {
  {
    "stevearc/conform.nvim",
    -- event = 'BufWritePre', -- uncomment for format on save
    config = function()
      require "configs.conform"
    end,
  },
  -- These are some examples, uncomment them if you want to see them work!
  --
  {
    "neovim/nvim-lspconfig",
    config = function()
      require("nvchad.configs.lspconfig").defaults()
      require "configs.lspconfig"
    end,
  },

  {
    "xeluxee/competitest.nvim",
    dependencies = "MunifTanjim/nui.nvim",
    keys = {
      { " rc", "<cmd>CompetiTest receive contest <CR>", { desc = "receive contest" } },
      { " rp", "<cmd>CompetiTest receive problem <CR>", { desc = "receive problem" } },
      { " rm", "<cmd>CompetiTest add_testcase <CR>", { desc = "add testcase" } },
      { " re", "<cmd>CompetiTest edit_testcase <CR>", { desc = "edit testcase" } },
      { " rr", "<cmd>CompetiTest run <CR>", { desc = "run code" } },
      { " rd", "<cmd>CompetiTest delete_testcase <CR>", { desc = "delete testcase" } },
    },
    config = function()
      require("competitest").setup {
        compile_command = {
          c = { exec = "gcc", args = { "-DRAMEZ", "-Wall", "$(FNAME)", "-o", "$(FNOEXT)" } },
          cpp = { exec = "g++", args = { "-std=c++17", "-DRAMEZ", "-Wall", "$(FNAME)", "-o", "$(FNOEXT)", "-g" } },
          py = { exec = "python", args = { "$(FNAME)" } },
          rust = { exec = "rustc", args = { "$(FNAME)" } },
          java = { exec = "javac", args = { "$(FNAME)" } },
        },
        received_problems_path = "$(HOME)/Storage/Problem-Solving/Problems/$(PROBLEM).$(FEXT)",
        received_contests_directory = "$(HOME)/Storage/Problem-Solving/Problems/",
        received_contests_problems_path = "$(PROBLEM).$(FEXT)",
        received_problems_prompt_path = false,
        testcases_use_single_file = true,
        evaluate_template_modifiers = true,
        received_contests_prompt_directory = false,
        received_contests_prompt_extension = false,
        open_received_contests = false,
        received_files_extension = "cpp",
        template_file = {
          cpp = "./Storage/Problem-Solving/Resources/Template/CPP.cpp",
        },
      }
    end,
  },
  {
    "williamboman/mason.nvim",
    opts = {
      ensure_installed = {
        "clangd",
        "lua-language-server",
        "stylua",
        "html-lsp",
        "css-lsp",
        "prettier",
      },
    },
  },
  --
  --
  -- {
  -- 	"nvim-treesitter/nvim-treesitter",
  -- 	opts = {
  -- 		ensure_installed = {
  -- 			"vim", "lua", "vimdoc",
  --      "html", "css"
  -- 		},
  -- 	},
  -- },
}

return plugins

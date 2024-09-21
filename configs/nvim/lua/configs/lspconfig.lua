-- EXAMPLE

local on_attach = require("nvchad.configs.lspconfig").on_attach
local on_init = require("nvchad.configs.lspconfig").on_init
local capabilities = require("nvchad.configs.lspconfig").capabilities

local lspconfig = require "lspconfig"
local servers = { "html", "cssls"--[[ , "clangd" ]] }

-- lsps with default config
for _, lsp in ipairs(servers) do
  lspconfig[lsp].setup {
    on_attach = on_attach,
    on_init = on_init,
    capabilities = capabilities,
  }
end

-- typescript
lspconfig.ts_ls.setup {
  on_attach = on_attach,
  on_init = on_init,
  capabilities = capabilities,
}


 lspconfig.clangd.setup {
   on_attach = on_attach,
   on_init = on_init,
   capabilities = capabilities,
   cmd = { "clangd", "--background-index", "--clang-tidy" },
   filetypes = { "c", "cpp", "objc", "objcpp" },
   root_dir = lspconfig.util.root_pattern("compile_commands.json", "compile_flags.txt", ".git"),
   single_file_support = true
 }

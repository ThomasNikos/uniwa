import adapter from '@sveltejs/adapter-static';
import { vitePreprocess } from '@sveltejs/vite-plugin-svelte';
/** @type {import('@sveltejs/kit').Config} */
const config = {
	kit: {
		// Static build for GitHub Pages; 404.html lets unknown URLs fall back to the SPA
		adapter: adapter({ fallback: '404.html' }),
		paths: {
			base: process.env.BASE_PATH ?? ''
		}
	},
	preprocess: vitePreprocess()
};

export default config;

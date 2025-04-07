/** @type {import('tailwindcss').Config} */
export default {
	content: ['./src/**/*.{html,js,svelte,ts}'],
	theme: {
		extend: {
			spacing: {
				'15': '60px',
			  },
			  colors: {
				'comb-white': '#FAF3DD',
				'comb-gray': '#696D7D',
				'comb-cyan': '#68B0AB',
				'comb-blue': '#8fc0a9',
			  },
			  backgroundImage: {
				'bg-1': "url('/src/lib/images/bg-1.jpg')",
				'bg-2': "url('/src/lib/images/bg-2.jpg')",
				'bg-3': "url('/src/lib/images/bg-3.jpg')",
			  },
			  screens: {
				'tab': '768px',
				'desk': '1024px',
				'wide': '1280px',
			  },
		},
		container: {
			center: true,
			screens: {
				sm: '600px',
				md: '728px',
				lg: '984px',
				xl: '1240px',
				'2xl': '1496px'
			},
			padding: {
				DEFAULT: '1rem',
				sm: '2rem',
				lg: '4rem',
				xl: '5rem',
				'2xl': '6rem'
			}
		}
	},
	plugins: []
};

import { useEffect, useState } from "react";

export default function QuizSetting() {
	const [categories, setCategories] = useState([]);

	useEffect(() => {
		fetch("/api/categories/all")
			.then((resp) => resp.json())
			.then((data) => {
				setCategories(data.categories);
			});
	}, []);

	return (
		<>
			<form action="/quiz/start" method="get">
				<ul>
					<CategoryList categories={categories} />
				</ul>
				<button type="submit">Start Quiz</button>
			</form>
		</>
	);
}

function CategoryList({ categories }) {
	return categories.map((category) => {
		return (
			<li key={category.ID}>
				<input
					id={category.ID}
					name="categoryId"
					type="radio"
					value={category.ID}
				/>
        <label htmlFor={category.ID}>{category.Name}</label>
			</li>
		);
	});
}
